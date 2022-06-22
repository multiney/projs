import java.util.ArrayList;
import java.util.List;

public class MeasureTime {

    public static void measureTime() {
        String filePath = "F:/levelorder.txt";
        List<TreeNode> trees = TreeOperation.createTreesList(filePath);
        double totalTime = 0;
        for (int i = 0; i < 10; ++i) {
            long start = System.currentTimeMillis();
            for (TreeNode tree : trees)
                TreeOperation.pathSum(tree, 5000);
            totalTime += System.currentTimeMillis() - start;
        }

        double averageTime = totalTime / 10.0;
        System.out.println(averageTime + " milliseconds");
    }

    public static void measureOrderTime() {
        String folderPath = "F:/";
        // levelorder
        List<List<Integer>> levelorderLLI = ReadFile.readFileToList(folderPath + "levelorder.txt");
        List<int[]>  levelorderLA = new ArrayList<>();
        for (List<Integer> li : levelorderLLI)
            levelorderLA.add(Utils.listToArray(li));

        // preorder
        List<List<Integer>> preorderLLI = ReadFile.readFileToList(folderPath + "preorder.txt");
        List<int[]> preorderLA = new ArrayList<>();
        for (List<Integer> li : preorderLLI)
            preorderLA.add(Utils.listToArray(li));

        // inorder
        List<List<Integer>> inorderLLI = ReadFile.readFileToList(folderPath + "inorder.txt");
        List<int[]> inorderLA = new ArrayList<>();
        for (List<Integer> li : inorderLLI)
            inorderLA.add(Utils.listToArray(li));

        // postorder
        List<List<Integer>> postorderLLT = ReadFile.readFileToList(folderPath + "postorder.txt");
        List<int[]> postorderLA = new ArrayList<>();
        for (List<Integer> li : postorderLLT)
            postorderLA.add(Utils.listToArray(li));

        double totalTime = 0;
        for (int i = 0; i < 10; ++i) {
            double start = System.currentTimeMillis();
//            for (int j = 0; j < inorderLA.size(); ++j)
//                TreeOperation.buildTreeInPost(preorderLA.get(j), inorderLA.get(j));
            for (int[] a : levelorderLA)
                TreeOperation.constructMaximumBinaryTree(a);
            totalTime += System.currentTimeMillis() - start;
        }

        double averageTime = totalTime / 10;
        System.out.println(averageTime + " milliseconds.");
    }

    public static void main(String[] args) {
        measureOrderTime();
    }
}
