

import java.util.List;

public class MeasureTime {

    public static void measureTime() {
        List<TreeNode> trees = TreeOperation.createTreesList();
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

    public static void main(String[] args) {
        measureTime();
    }
}
