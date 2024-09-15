/*
The MIT License (MIT)

Copyright (c) 2024 sigma-axis

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <cstdint>
#include <cstring>
#include <bit>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

using byte = uint8_t;
#include <aviutl/FilterPlugin.hpp>

#include "key_states.hpp"
using namespace sigma_lib::W32::UI;

////////////////////////////////
// ExEdit 実体．
////////////////////////////////
inline constinit struct ExEdit092 {
	AviUtl::FilterPlugin* fp;
	constexpr static char const* info_exedit092 = "拡張編集(exedit) version 0.92 by ＫＥＮくん";
	bool init(AviUtl::FilterPlugin* this_fp)
	{
		if (fp != nullptr) return true;
		AviUtl::SysInfo si; this_fp->exfunc->get_sys_info(nullptr, &si);
		for (int i = 0; i < si.filter_n; i++) {
			auto that_fp = this_fp->exfunc->get_filterp(i);
			if (that_fp->information != nullptr &&
				0 == std::strcmp(that_fp->information, info_exedit092)) {
				fp = that_fp;
				init_pointers();
				return true;
			}
		}
		return false;
	}

	decltype(fp->func_WndProc) func_wndproc_orig;
	SIZE*	timeline_size; // 0x1a52fc, excludes right vertical scroll bar.

private:
	void init_pointers()
	{
		auto pick_addr = [exedit_base=reinterpret_cast<uintptr_t>(fp->dll_hinst)]
			<class T>(T& target, ptrdiff_t offset) { target = std::bit_cast<T>(exedit_base + offset); };

		func_wndproc_orig = fp->func_WndProc;
		pick_addr(timeline_size, 0x1a52fc);
	}
} exedit;


////////////////////////////////
// ExEdit の乗っ取り関数の定義．
////////////////////////////////
BOOL exedit_func_wndproc_hook(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam, AviUtl::EditHandle* editp, AviUtl::FilterPlugin* fp)
{
	constexpr int tl_origin_x = 64, tl_origin_y = 42,
		gauge_top = 21, scrollbar_thick = 13;

	switch (message) {
	case WM_MOUSEWHEEL:
		POINT pt{ static_cast<int16_t>(lparam), static_cast<int16_t>(lparam >> 16) };
		::ScreenToClient(hwnd, &pt);
		if (pt.y < exedit.timeline_size->cy && (
			(0 <= pt.x && pt.x < tl_origin_x && gauge_top <= pt.y) ||
			(exedit.timeline_size->cx <= pt.x && pt.x < exedit.timeline_size->cx + scrollbar_thick &&
				scrollbar_thick <= pt.y))) {
			if (pt.y >= tl_origin_y || pt.x >= tl_origin_x) {
				wparam &= ~MK_CONTROL;
				ForceKeyState k{ VK_MENU, flag_map::inv };
				return exedit.func_wndproc_orig(hwnd, message, wparam, lparam, editp, fp);
			}

			wparam |= MK_CONTROL;
		}
		break;
	}

	return exedit.func_wndproc_orig(hwnd, message, wparam, lparam, editp, fp);
}


////////////////////////////////
// AviUtlに渡す関数の定義．
////////////////////////////////
BOOL func_init(AviUtl::FilterPlugin* fp)
{
	if (!exedit.init(fp)) {
		::MessageBoxA(fp->hwnd, "拡張編集0.92が見つかりませんでした．",
			fp->name, MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	// コールバック関数差し替え．
	exedit.fp->func_WndProc = exedit_func_wndproc_hook;

	return TRUE;
}


////////////////////////////////
// Entry point.
////////////////////////////////
BOOL WINAPI DllMain(HINSTANCE hinst, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		::DisableThreadLibraryCalls(hinst);
		break;
	}
	return TRUE;
}


////////////////////////////////
// 看板．
////////////////////////////////
#define PLUGIN_NAME		"Layer Wheel 2"
#define PLUGIN_VERSION	"v1.11"
#define PLUGIN_AUTHOR	"sigma-axis"
#define PLUGIN_INFO_FMT(name, ver, author)	(name##" "##ver##" by "##author)
#define PLUGIN_INFO		PLUGIN_INFO_FMT(PLUGIN_NAME, PLUGIN_VERSION, PLUGIN_AUTHOR)

extern "C" __declspec(dllexport) AviUtl::FilterPluginDLL * __stdcall GetFilterTable(void)
{
	// （フィルタとは名ばかりの）看板．
	using Flag = AviUtl::FilterPlugin::Flag;
	static constinit AviUtl::FilterPluginDLL filter{
		.flag = Flag::NoConfig | Flag::AlwaysActive | Flag::ExInformation,
		.name = PLUGIN_NAME,

		.func_init = func_init,
		.information = PLUGIN_INFO,
	};
	return &filter;
}
