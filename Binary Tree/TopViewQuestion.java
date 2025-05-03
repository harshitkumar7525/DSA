import java.util.*;

// Node class banaya jo binary tree ka ek node represent karega
class Node {
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
    }
}

public class TopViewQuestion {

    // Info class banayi jisme node ke sath uska horizontal distance (hd) store karenge
    static class Info {
        Node node;
        int hd;
        Info(Node node, int hd){
            this.node = node;
            this.hd = hd;
        }
    }

    // Top view nikalne wali function
    static ArrayList<Integer> topView(Node root) {
        // Agar root null hai toh empty list return karo
        if(root == null){
            return new ArrayList<>();
        }

        // TreeMap use kiya hai kyunki hume left to right sorted order chahiye
        TreeMap<Integer, Integer> map = new TreeMap<>();
        
        // Queue banayi for level order traversal (BFS)
        Queue<Info> q = new LinkedList<>();
        q.offer(new Info(root, 0)); // root ka hd 0 se start karte hain

        // BFS start
        while(!q.isEmpty()){
            Info curr = q.poll(); // Queue se current info nikalo
            int hd = curr.hd;
            Node node = curr.node;

            // Agar is hd pe pehli baar node aa rahi hai, toh hi usko map me daalo
            if(!map.containsKey(hd)){
                map.put(hd, node.data);
            }

            // Left child ko queue me daalo with hd - 1
            if(node.left != null){
                q.offer(new Info(node.left, hd - 1));
            }

            // Right child ko queue me daalo with hd + 1
            if(node.right != null){
                q.offer(new Info(node.right, hd + 1));
            }
        }

        // Final result nikalne ke liye map ke values ko ArrayList me daal do
        return new ArrayList<>(map.values());
    }

    public static void main(String[] args) {
        // Sample binary tree create kiya
        Node root = new Node(1);
        root.left = new Node(2);
        root.left.right = new Node(4);
        root.left.right.right = new Node(5);
        root.left.right.right.right = new Node(6);
        root.right = new Node(3);

        // Top view call kiya
        ArrayList<Integer> topview = topView(root);

        // Output print kiya
        for(var i : topview){
            System.out.print(i + " ");
        }
    }
}
