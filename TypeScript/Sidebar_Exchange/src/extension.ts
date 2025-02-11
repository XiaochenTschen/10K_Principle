import * as vscode from 'vscode';
import { LoginViewProvider } from './views/LoginViewProvider';
import { VPContainerViewProvider } from './views/VPContainerViewProvider';
import { ContainerItem } from './views/VPContainerTreeview/ContainerItem';

export function activate(context: vscode.ExtensionContext) {
    // login webview
    context.subscriptions.push(
        vscode.window.registerWebviewViewProvider('loginView', new LoginViewProvider(context))
    );

    // vp container treeview
    const containerView = new VPContainerViewProvider(context);
    vscode.window.registerTreeDataProvider('VPContainerView', containerView);
    context.subscriptions.push(
      vscode.commands.registerCommand(
        'containerView.run',
        (item: ContainerItem) => {
          vscode.window.showInformationMessage(`Running: ${item.label}`);
          containerView.runItem(item);
        }
      )
    );

    context.subscriptions.push(
      vscode.commands.registerCommand(
        'containerView.stop',
        (item: ContainerItem) => {
          vscode.window.showInformationMessage(`Stopping: ${item.label}`);
          containerView.stopItem(item);
        }
      )
    );
}

export function deactivate() {}