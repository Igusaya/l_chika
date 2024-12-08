# VS Code で L チカを実行する方法

このガイドでは、Arduino Pro Micro 互換ボードを使用して、LED を点滅（L チカ）させる手順を説明します。

## 必要なもの

- Arduino Pro Micro 互換ボード
- VS Code
- Arduino CLI
- Arduino Community Edition プラグイン

## Arduino CLI のインストール

Arduino CLI をインストールするには、公式ドキュメントを参照してください:

[Arduino CLI Installation Guide](https://arduino.github.io/arduino-cli/0.35/installation/)

ここでは、Homebrew を使用してインストールする手順を紹介します。

### インストール手順

1. Homebrew の更新と CLI のインストール

```bash
brew update
brew install arduino-cli
```

2. ボードインデックスとパッケージのインストール

```bash
arduino-cli core update-index
arduino-cli core install esp32:esp32
```

## Arduino Community Edition プラグインのインストールと設定

VS Code 用の公式 Arduino プラグイン（Microsoft 製）は開発終了したため、代わりに Arduino Community Edition プラグインを使用します。

### プラグインのインストール

1. VS Code の拡張機能マーケットプレイスで「Arduino Community Edition」を検索し、インストールします。  
   識別子: vscode-arduino.vscode-arduino-community

2. コマンドパレット（Cmd+Shift+P または Ctrl+Shift+P）を開き、Arduino: Initialize を選択します。

### `settings.json`の設定

以下を`settings.json`に追加してください。

```json
{

  ...

  "arduino.useArduinoCli": true,
  "arduino.path": "/opt/homebrew/bin", // Arduino CLIのパス
  "arduino.commandPath": "arduino-cli", // Arduino CLIのコマンド名
  "arduino.additionalUrls": [
    "https://dl.espressif.com/dl/package_esp32_index.json" // ボードマネージャの URL
  ],
  "arduino.disableIntelliSenseAutoGen": false, // .vscode/c_cpp_properties.json ファイルが自動生成されないようにする
  "C_Cpp.intelliSenseEngine": "Tag Parser"
}
```

### CLI パスの確認

`arduino-cli`のインストール先を確認するには、以下を実行します。

```bash
which arduino-cli
# 例：  /opt/homebrew/bin/arduino-cli
```

## シリアルポートの選択

1. 接続確認：ターミナルで以下を実行して、接続されているポートを確認します。

```bash
ls /dev/tty*
```

例：`/dev/tty.usbmodem****`がリストに表示されていれば、ボードが正しく接続されています。

2. VS Code でポートの選択

- vscode 右下に`<selected serial port>`と表示されます。
- クリックして`/dev/tty.usbmodem****` を選択します。

## ボードの選択

vscode 右下の`<selected board>`をクリックし、以下を選択します。

- `Arduino Leonardo (Arduino AVR Board)`

もし`Arduino Leonardo (Arduino AVR Board)`が選択肢に存在しない場合、下記手順をお試し下さい。

1. コマンドパレット（Cmd+Shift+P または Ctrl+Shift+P）を開き、Arduino: Selected Board を選択します。
2. Arduino AVR Boards をインストールする。

## コーディング

`l_chika.ino`ファイルを作成し、以下のコードを記述します。

```ino
void setup() {
    pinMode(17, OUTPUT); // デジタルピン17を出力モードに設定
}

void loop() {
    digitalWrite(17, HIGH); // LEDをON
    delay(1000);            // 1秒間待機
    digitalWrite(17, LOW);  // LEDをOFF
    delay(1000);            // 1秒間待機
}
```

> 備考：  
> ピン 17 はオンボードの RX LED（USB コネクタを上にした場合、左下の LED）に対応しています。

## アップロード

1. コードの検証: コマンドパレットで `Arduino: Verify` を選択し、エラーがないことを確認します。

2. コードのアップロード: コマンドパレットで `Arduino: Upload` を選択し、ボードにスケッチをアップロードします。

3. 動作確認: ボード上の LED が 1 秒間隔で点滅すれば成功です。

## 補足

- 本ガイドは ESP32 用の追加設定も含んでいますが、Arduino Pro Micro 互換ボードの基本的な使い方に焦点を当てています。
- 設定や手順で不明な点がある場合は、公式ドキュメントやコミュニティを活用してください。
- 本ガイドは ChatGPT さんに添削してもらいました。
