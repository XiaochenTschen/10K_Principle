import * as vscode from 'vscode';

export function activate(context: vscode.ExtensionContext) {
  const loginProvider = new LoginViewProvider(context.extensionUri);

  // 注册视图
  context.subscriptions.push(
    vscode.window.registerWebviewViewProvider(LoginViewProvider.viewType, loginProvider)
  );
}

export function deactivate() {}

export class LoginViewProvider implements vscode.WebviewViewProvider {
  public static readonly viewType = 'myExtension.loginView';

  constructor(private readonly _extensionUri: vscode.Uri) {}

  public resolveWebviewView(webviewView: vscode.WebviewView) {
    webviewView.webview.options = {
      enableScripts: true,
      localResourceRoots: [this._extensionUri],
    };

    webviewView.webview.html = this._getHtmlForWebview(webviewView.webview);
    webviewView.webview.onDidReceiveMessage((message) => {
      if (message.command === 'login') {
        vscode.window.showInformationMessage(`Logged in as: ${message.username}`);
      }
    });
  }

  private _getHtmlForWebview(webview: vscode.Webview): string {
    const nonce = this._getNonce();
    return `
      <!DOCTYPE html>
      <html lang="en">
      <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script nonce="${nonce}">
          const vscode = acquireVsCodeApi();

          function login() {
            const username = document.getElementById('username').value;
            const password = document.getElementById('password').value;
            vscode.postMessage({ command: 'login', username, password });
          }
        </script>
      </head>
      <body>
        <div style="padding: 10px;">
          <h2>Login</h2>
          <input id="username" type="text" placeholder="Username" style="width: 100%; margin-bottom: 10px;" />
          <input id="password" type="password" placeholder="Password" style="width: 100%; margin-bottom: 10px;" />
          <button onclick="login()" style="width: 100%;">Login</button>
        </div>
      </body>
      </html>
    `;
  }

  private _getNonce(): string {
    let text = '';
    const possible = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    for (let i = 0; i < 32; i++) {
      text += possible.charAt(Math.floor(Math.random() * possible.length));
    }
    return text;
  }
}
