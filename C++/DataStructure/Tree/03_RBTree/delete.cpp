// 假设Node已经定义，包含颜色、值、左右子节点和父节点指针
void deleteNode(Node*& root, Node* nodeToDelete) {
    if (nodeToDelete == nullptr) return;

    // 1. 找到真正要删除的节点和它的替换节点（后继节点或实际要删除的节点）
    Node* replacement = (nodeToDelete->left != nullptr && nodeToDelete->right != nullptr)
                          ? findSuccessor(nodeToDelete->right) : nodeToDelete;

    // 2. 确定替换节点的子节点
    Node* replacementChild = (replacement->left != nullptr) ? replacement->left : replacement->right;

    // 3. 如果替换节点的子节点不为空，更新父节点指针
    if (replacementChild != nullptr) {
        replacementChild->parent = replacement->parent;
    }

    // 4. 如果替换节点是根节点，更新根节点指针
    if (replacement->parent == nullptr) {
        root = replacementChild;
    } else if (replacement == replacement->parent->left) { // 更新父节点的子节点指针
        replacement->parent->left = replacementChild;
    } else {
        replacement->parent->right = replacementChild;
    }

    // 5. 如果替换节点不是要删除的节点，将其值复制到要删除的节点
    if (replacement != nodeToDelete) {
        nodeToDelete->value = replacement->value; // 假设value是节点存储的数据
    }

    // 6. 如果替换节点是黑色，需要调整树
    if (replacement->color == BLACK) {
        deleteFixup(root, replacementChild, replacement->parent);
    }

    delete replacement; // 删除替换节点
}

// findSuccessor, deleteFixup等函数需要根据红黑树的特性实现
