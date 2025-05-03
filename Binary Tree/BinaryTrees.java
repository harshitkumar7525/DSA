
import java.util.*;

public class BinaryTrees {

    static class Node {

        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    static class BinaryTree {

        static int idx = -1;

        public static Node buildTree(int nodes[]) {
            idx++;
            if (nodes[idx] == -1) {
                return null;
            }
            Node newNode = new Node(nodes[idx]);
            newNode.left = buildTree(nodes);
            newNode.right = buildTree(nodes);
            return newNode;
        }

        // preorder, inorder, postorder are examples of DFS
        public static void preOrder(Node root) {
            if (root == null) {
                return;
            }
            System.out.print(root.data + " ");
            preOrder(root.left);
            preOrder(root.right);
        }

        public static void inOrder(Node root) {
            if (root == null) {
                return;
            }
            preOrder(root.left);
            System.out.print(root.data + " ");
            preOrder(root.right);
        }

        public static void postOrder(Node root) {
            if (root == null) {
                return;
            }
            preOrder(root.left);
            preOrder(root.right);
            System.out.print(root.data + " ");
        }

        //Level order is BFS
        public static void levelOrder(Node root) {
            if (root == null) {
                return;
            }
            Queue<Node> q = new LinkedList<>();
            q.offer(root);
            q.offer(null);
            while (!q.isEmpty()) {
                Node temp = q.poll();
                if(temp==null && !q.isEmpty()){
                    System.out.println();
                    q.offer(null);
                }
                else if (temp==null && q.isEmpty()){
                    break;
                }
                else{
                    if (temp != null) {
                        System.out.print(temp.data + " ");
                    }
                }
                if (temp != null) {
                    if (temp.left != null) {
                        q.offer(temp.left);
                    }
                    if (temp.right != null) {
                        q.offer(temp.right);
                    }
                }
            }
        }

        public static int countNodes(Node root) {
            if (root == null) {
                return 0;
            }
            return 1 + countNodes(root.left) + countNodes(root.right);
        }

        public static int sumOfNodes(Node root) {
            if (root == null) {
                return 0;
            } else {
                return root.data + sumOfNodes(root.left) + sumOfNodes(root.right);
            }
        }

        public static int heightOfTreeViaNode(Node root) {
            if (root == null) {
                return 0;
            } else {
                return Math.max(heightOfTreeViaNode(root.left), heightOfTreeViaNode(root.right)) + 1;
            }
        }

        public static int heightOfTreeViaEdge(Node root) {
            if (root == null) {
                return -1; 
            }else {
                return Math.max(heightOfTreeViaEdge(root.left), heightOfTreeViaEdge(root.right)) + 1;
            }
        }
        public static int diameterViaNode(Node root){
            if(root==null){
                return 0;
            }
            int rightDiameter = diameterViaNode(root.right);
            int leftDiameter = diameterViaNode(root.left);
            int rightHeight = heightOfTreeViaNode(root.right);
            int leftHeight = heightOfTreeViaNode(root.left);
            int selfHeight = rightHeight+leftHeight+1;
            return Math.max(Math.max(rightDiameter,leftDiameter),selfHeight);
        }

        static class TreeInfo{
            int height;
            int diameter;

            public TreeInfo(int height,int diameter) {
                this.height=height;
                this.diameter=diameter;
            }
            public TreeInfo() {
            }
        }

        public static TreeInfo diameterHelperViaNode(Node root){
            if(root==null){
                return new TreeInfo(0,0);
            }
            TreeInfo leftInfo = diameterHelperViaNode(root.left);
            TreeInfo rightInfo = diameterHelperViaNode(root.right);
            int currSelfDiameter = leftInfo.height+rightInfo.height+1;
            int currDiameter = Math.max(Math.max(rightInfo.diameter,leftInfo.diameter),currSelfDiameter);
            int currHeight = Math.max(leftInfo.height,rightInfo.height)+1;
            TreeInfo selfInfo = new TreeInfo(currHeight,currDiameter);
            return selfInfo;
        }
        public static int diameterOptimizedViaNode(Node root){
            return diameterHelperViaNode(root).diameter;
        }
        public static int diameterViaEdge(Node root) {
            if (root == null) return 0;
        
            int leftDiameter = diameterViaEdge(root.left);
            int rightDiameter = diameterViaEdge(root.right);
        
            int leftHeight = heightOfTreeViaEdge(root.left);
            int rightHeight = heightOfTreeViaEdge(root.right);
        
            int selfDiameter = leftHeight + rightHeight+2;
        
            return Math.max(selfDiameter, Math.max(leftDiameter, rightDiameter));
        }
        public static TreeInfo diameterHelperViaEdge(Node root) {
            if (root == null) {
                return new TreeInfo(-1, 0); // height = -1 for edge-based
            }
        
            TreeInfo leftInfo = diameterHelperViaEdge(root.left);
            TreeInfo rightInfo = diameterHelperViaEdge(root.right);
        
            int selfDiameter = leftInfo.height + rightInfo.height + 2;
            int maxDiameter = Math.max(selfDiameter, Math.max(leftInfo.diameter, rightInfo.diameter));
            int selfHeight = Math.max(leftInfo.height, rightInfo.height) + 1;
        
            return new TreeInfo(selfHeight, maxDiameter);
        }
        
        public static int diameterOptimizedViaEdge(Node root) {
            return diameterHelperViaEdge(root).diameter;
        }
        
    }

    @SuppressWarnings("static-access")
    public static void main(String[] args) {
        int[] nodes = {1,2,4,8,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
        BinaryTree tree = new BinaryTree();
        Node root = tree.buildTree(nodes);
        System.out.print("Preorder: ");
        tree.preOrder(root); //TC=O(n)
        System.out.println();
        System.out.print("Inorder: ");
        tree.inOrder(root); //TC=O(n)
        System.out.println();
        System.out.print("Postorder: ");
        tree.postOrder(root); //TC=O(n)
        System.out.println();
        System.out.println("Level order: ");
        tree.levelOrder(root); //TC=O(n)
        System.out.println();
        System.out.println("The number of nodes in this tree is " + tree.countNodes(root)); //TC=O(n)
        System.out.println("The sum of all the nodes is " + tree.sumOfNodes(root)); //TC=O(n)
        System.out.println("The height of tree via Node: "+tree.heightOfTreeViaNode(root)); //TC=O(n)
        System.out.println("The height of tree via Edge: "+tree.heightOfTreeViaEdge(root)); //TC=O(n)
        System.out.println("The diameter of the tree via Node is: "+tree.diameterViaNode(root)); //  TC=O(n2)
        System.out.println("The diameter(optimized) of the tree via Node is: "+tree.diameterOptimizedViaNode(root)); // TC=O(n)
        System.out.println("The diameter of the tree via Edge is: "+tree.diameterViaEdge(root)); //  TC=O(n2)
        System.out.println("The diameter(optimized) of the tree via Edge is: "+tree.diameterOptimizedViaEdge(root)); // TC=O(n)
    }
}
