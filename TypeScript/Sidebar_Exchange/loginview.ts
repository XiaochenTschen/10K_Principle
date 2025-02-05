import * as vscode from 'vscode';

export class StatusViewProvider implements vscode.WebviewViewProvider {
  public static readonly viewType = 'statusView';

  constructor(private readonly context: vscode.ExtensionContext) {}

  resolveWebviewView(webviewView: vscode.WebviewView): void {
    webviewView.webview.options = {
      enableScripts: true,
    };

    webviewView.webview.html = this.getHtml();
  }

  private getHtml(): string {
    return `
      <!DOCTYPE html>
      <html lang="en">
      <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <style>
          body {
            font-family: var(--vscode-font-family);
            color: var(--vscode-foreground);
            background-color: var(--vscode-editor-background);
            padding: 10px;
          }
        </style>
        <title>Status View</title>
      </head>
      <body>
        <h2>状态信息</h2>
        <p>当前没有可显示的状态。</p>
      </body>
      </html>
    `;
  }
}

