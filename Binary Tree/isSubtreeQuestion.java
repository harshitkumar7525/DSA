// Binary Tree ka node class
class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;  // initially dono child null hote hain
    }
}

public class isSubtreeQuestion {

    // Dono trees identical hai ya nahi yeh check karta hai
    private static boolean isIdentical(Node node, Node subroot) {
        // Agar dono null hain to identical hai
        if (node == null && subroot == null) {
            return true;
        }
        // Agar koi ek null hai ya data match nahi kar raha to identical nahi hain
        else if (node == null || subroot == null || node.data != subroot.data) {
            return false;
        } else {
            // Recursively left aur right subtree ko check karo
                if(!isIdentical(node.left,subroot.left)){ //agar left identical nhi hai to false return kardo
                    return false;
                } else if(!isIdentical(node.right,subroot.right)){ //agar right identical nahi hai toh false return kardo
                    return false;
                } else { // agar dono identical hai toh true return kardo
                    return true;
                }
        }
    }

    // root me subroot subtree ke form me present hai ya nahi yeh check karta hai
    public static boolean isSubtree(Node root, Node subroot) {
        // Agar main tree ka root hi null hai to kuch bhi subtree nahi ho sakta
        if (root == null) {
            return false;
        }

        // Agar current node ka data subroot se match kar raha hai
        if (root.data == subroot.data) {
            // To check karo ki dono trees identical hai ya nahi
            if (isIdentical(root, subroot)) {
                return true;
            }
        }

        // Agar current node match nahi kar raha to left aur right subtree me check karo
        return isSubtree(root.left, subroot) || isSubtree(root.right, subroot);
    }

    public static void main(String[] args) {
        /*
            Main tree:
                        1
                       / \
                      2   3
                     / \
                    4   5

            Subtree (check karna hai):
                        2
                       / \
                      4   5
        */

        // Main tree banaya
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        // Subtree banaya jisko check karna hai
        Node subroot = new Node(2);
        subroot.left = new Node(4);
        subroot.right = new Node(5);

        // Function call karke result check kiya
        boolean result = isSubtree(root, subroot);
        System.out.println("Is subtree: " + result);  // Output: true
    }
}
