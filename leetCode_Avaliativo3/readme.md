Carlos Felipe Pereira Bellomo - M2

701. Insert into a Binary Search Tree
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Dificuldades: 

1- Entender qual a maneira certa de usar a recursão, ex:
    apenas chamar função | "insertBST(root,val)"
    chamar atribuindo a uma variável | "root->left = insertBST(root,val)"
    chamar utilizando return | return "insertBST(root,val)"

Complexity : O(logn)
