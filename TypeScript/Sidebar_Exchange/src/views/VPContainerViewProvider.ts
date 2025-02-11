import * as vscode from 'vscode';
import { ContainerItem } from './VPContainerTreeview/ContainerItem';

export class VPContainerViewProvider implements vscode.TreeDataProvider<ContainerItem> {
  private items: ContainerItem[] = [];
  private _onDidChangeTreeData: vscode.EventEmitter<ContainerItem | undefined> = new vscode.EventEmitter<ContainerItem | undefined>();
  readonly onDidChangeTreeData: vscode.Event<ContainerItem | undefined> = this._onDidChangeTreeData.event;

  constructor(private context: vscode.ExtensionContext) {
    this.items = [
      new ContainerItem("Container A", this.context.extensionPath, "plug"),
      new ContainerItem("Container B", this.context.extensionPath, "plug"),
    ];
  }

  getTreeItem(element: ContainerItem): vscode.TreeItem {
    return element;
  }

  getChildren(): ContainerItem[] {
    return this.items;
  }

  refresh(): void {
    this._onDidChangeTreeData.fire(undefined);
  }

  runItem(item: ContainerItem): void {
    item.updateStatus(true);
    this.refresh();
  }

  stopItem(item: ContainerItem): void {
    item.updateStatus(false);
    this.refresh();
  }
}
