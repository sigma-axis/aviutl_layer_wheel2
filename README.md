# Layer Wheel 2 AviUtlプラグイン

拡張編集のレイヤーの部分でマウスホイールすると縦スクロールになったり，拡大率のゲージ部分だとタイムラインの拡大縮小ができるプラグイン．[ダウンロードはこちら．](https://github.com/sigma-axis/aviutl_layer_wheel2/releases)

![操作説明](https://github.com/user-attachments/assets/5ab5c3c6-e27a-4188-ab19-0183cb09ef5c)

nazoSAUNA様の [LayerWheel](https://github.com/nazonoSAUNA/LayerWheel) プラグインの別実装 + 機能追加版です．


## 動作要件

- AviUtl 1.10 + 拡張編集 0.92

  https://spring-fragrance.mints.ne.jp/aviutl
  - 拡張編集 0.93rc1 等の他バージョンでは動作しません．

- Visual C++ 再頒布可能パッケージ（\[2015/2017/2019/2022\] の x86 対応版が必要）

  https://learn.microsoft.com/ja-jp/cpp/windows/latest-supported-vc-redist

## 導入方法

以下のフォルダのいずれかに `layer_wheel2.auf` をコピーしてください．

1.  `aviutl.exe` のあるフォルダ
1.  (1) のフォルダにある `plugins` フォルダ
1.  (2) のフォルダにある任意のフォルダ


## 使い方

1.  レイヤー左側部分でホイール操作をすると（本来なら横方向なのが）縦方向にスクロールします．

1.  左上のゲージ部分でホイール操作すると，タイムラインの拡大率が変化します．

![操作説明](https://github.com/user-attachments/assets/5ab5c3c6-e27a-4188-ab19-0183cb09ef5c)


## 謝辞

このプラグインの着想は全面的に [LayerWheel](https://github.com/nazonoSAUNA/LayerWheel) から来ています．実装方法が異なるのでフォークのような関連性はありませんが，LayerWheel がなければこのプラグインを作成することはありませんでした．この場で恐縮ですが開発のヒントになったことに感謝申し上げます．


## 改版履歴

- **v1.10** (2024-09-03)

  - 左のレイヤー部分に加えて，縦スクロールバー上にマウスカーソルがあっても縦スクロールするように変更．

- **v1.00** (2024-09-03)

  - 初版．

## ライセンス

このプログラムの利用・改変・再頒布等に関しては MIT ライセンスに従うものとします．

---

The MIT License (MIT)

Copyright (C) 2024 sigma-axis

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

https://mit-license.org/


#  Credits

##  aviutl_exedit_sdk

https://github.com/ePi5131/aviutl_exedit_sdk

---

1条項BSD

Copyright (c) 2022
ePi All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
THIS SOFTWARE IS PROVIDED BY ePi “AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL ePi BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


#  連絡・バグ報告

- GitHub: https://github.com/sigma-axis
- Twitter: https://x.com/sigma_axis
- nicovideo: https://www.nicovideo.jp/user/51492481
- Misskey.io: https://misskey.io/@sigma_axis
- Bluesky: https://bsky.app/profile/sigma-axis.bsky.social

