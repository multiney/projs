import sun.reflect.generics.tree.Tree;
import sun.util.locale.provider.JRELocaleProviderAdapter;

import java.util.*;

public class TreeOperation {

    public static TreeNode createTreeByLevel(List<Integer> list) {
        int len = list.size();
        if (len == 0 || list.get(0) == -1) return null;

        int index = 0;
        TreeNode root = new TreeNode(list.get(index++));
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);
        TreeNode p = null;

        while (!que.isEmpty() && index < len) {
            p = que.poll();

            if (list.get(index) != -1) {
                p.left = new TreeNode(list.get(index));
                que.offer(p.left);
            }
            ++index;

            if (index < len && list.get(index) != -1) {
                p.right = new TreeNode(list.get(index));
                que.offer(p.right);
            }
            ++index;
        }
        return root;
    }

    public static List<TreeNode> createTreesList(String filePath) {
//        String filePath = "F:\\strTrees.txt";
        List<TreeNode> trees = new ArrayList<>();
        TreeNode tree = null;
        List<List<Integer>> lists = ReadFile.readFileToList(filePath);

        for (int i = 0; i < lists.size(); ++i) {
            tree = createTreeByLevel(lists.get(i));
            trees.add(tree);
        }
        return trees;
    }

    /**
     * 144. Binary Tree Preorder Traversal
     * @param root
     * @return
     */
    public static List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        preorder(root, ret);
        return ret;
    }
    private static void preorder(TreeNode node, List<Integer> ret) {
        if (node == null) return;

        ret.add(node.val);
        preorder(node.left, ret);
        preorder(node.right, ret);
    }

    /**
     * Stack version
     * @param root
     * @return
     */
    public static List<Integer> preorderTraversalStk(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null){
            return result;
        }
        Stack<TreeNode> Stack = new Stack<>();
        Stack.push(root);
        while (!Stack.isEmpty()){
            TreeNode node = Stack.pop();
            result.add(node.val);
            if (node.right != null){
                Stack.push(node.right);
            }
            if (node.left != null){
                Stack.push(node.left);
            }
        }
        return result;
    }

    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<>();
        int depth = 0;
        levelTraversal(root, ret, depth);
        return ret;
    }

    private static void levelTraversal(TreeNode node, List<List<Integer>> ret, int depth) {
        if (node == null) return;
        if (ret.size() == depth) ret.add(new ArrayList<>());
        ret.get(depth).add(node.val);
        levelTraversal(node.left, ret, depth + 1);
        levelTraversal(node.right, ret, depth + 1);
    }

    /**
     * 404. Sum of Left Leaves
     * @param root
     * @return
     */
    public static int sumOfLeftLeaves(TreeNode root) {
        if (root == null) return 0;
        int leftValue = sumOfLeftLeaves(root.left);    // 左
        int rightValue = sumOfLeftLeaves(root.right);  // 右

        int midValue = 0;
        if (root.left != null && root.left.left == null && root.left.right == null) {
            midValue = root.left.val;
        }
        int sum = midValue + leftValue + rightValue;  // 中
        return sum;
    }

    public static int sumOfLeftLeavesStk(TreeNode root) {
        if (root == null) return 0;
        Stack<TreeNode> Stack = new Stack<> ();
        Stack.add(root);
        int result = 0;
        while (!Stack.isEmpty()) {
            TreeNode node = Stack.pop();
            if (node.left != null && node.left.left == null && node.left.right == null) {
                result += node.left.val;
            }
            if (node.right != null) Stack.add(node.right);
            if (node.left != null) Stack.add(node.left);
        }
        return result;
    }

    private static int Deep = -1;
    private static int value = 0;

    /**
     * 513. find bottom left tree value
     * @param root
     * @return
     */
    public static int findBottomLeftValue(TreeNode root) {
        value = root.val;
        findLeftValue(root,0);
        return value;
    }

    private static void findLeftValue (TreeNode root,int deep) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            if (deep > Deep) {
                value = root.val;
                Deep = deep;
            }
        }
        if (root.left != null) findLeftValue(root.left,deep + 1);
        if (root.right != null) findLeftValue(root.right,deep + 1);
    }

    public static int findBottomLeftValueQue(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int res = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode poll = queue.poll();
                if (i == 0) {
                    res = poll.val;
                }
                if (poll.left != null) {
                    queue.offer(poll.left);
                }
                if (poll.right != null) {
                    queue.offer(poll.right);
                }
            }
        }
        return res;
    }

    /**
     * 112. Path Sum
     * @param root
     * @param targetsum
     * @return
     */
    public static boolean hasPathSum(TreeNode root, int targetsum) {

        if (root == null) return false; // 为空退出

        // 叶子节点判断是否符合
        if (root.left == null && root.right == null) return root.val == targetsum;

        // 求两侧分支的路径和
        return hasPathSum(root.left, targetsum - root.val) || hasPathSum(root.right, targetsum - root.val);
    }

    public static boolean hasPathSumStk(TreeNode root, int targetsum) {
        if(root==null)return false;
        Stack<TreeNode> Stack1 = new Stack<>();
        Stack<Integer> Stack2 = new Stack<>();
        Stack1.push(root);Stack2.push(root.val);
        while(!Stack1.isEmpty()){
            int size = Stack1.size();
            for(int i=0;i<size;i++){
                TreeNode node = Stack1.pop();int sum=Stack2.pop();
                // 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
                if(node.left==null && node.right==null && sum==targetsum)return true;
                // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
                if(node.right!=null){
                    Stack1.push(node.right);Stack2.push(sum+node.right.val);
                }
                // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
                if(node.left!=null){
                    Stack1.push(node.left);Stack2.push(sum+node.left.val);
                }
            }
        }
        return false;
    }

    /**
     * Path Sum II
     * @param root
     * @param targetsum
     * @return
     */
    public static List<List<Integer>> pathSum(TreeNode root, int targetsum) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res; // 非空判断

        List<Integer> path = new LinkedList<>();
        preorderdfs(root, targetsum, res, path);
        return res;
    }

    private static void preorderdfs(TreeNode root, int targetsum, List<List<Integer>> res, List<Integer> path) {
        path.add(root.val);
        // 遇到了叶子节点
        if (root.left == null && root.right == null) {
            // 找到了和为 targetsum 的路径
            if (targetsum - root.val == 0) {
                res.add(new ArrayList<>(path));
            }
            return; // 如果和不为 targetsum，返回
        }

        if (root.left != null) {
            preorderdfs(root.left, targetsum - root.val, res, path);
            path.remove(path.size() - 1); // 回溯
        }
        if (root.right != null) {
            preorderdfs(root.right, targetsum - root.val, res, path);
            path.remove(path.size() - 1); // 回溯
        }
    }

    /**
     * 106. Construct Binary Tree from Inorder and Postorder Traversal
     * @param inorder
     * @param postorder
     * @return
     */
    public static TreeNode buildTreeInPost(int[] inorder, int[] postorder) {
        return buildTree1(inorder, 0, inorder.length, postorder, 0, postorder.length);
    }
    private static TreeNode buildTree1(int[] inorder, int inLeft, int inRight,
                               int[] postorder, int postLeft, int postRight) {
        // 没有元素了
        if (inRight - inLeft < 1) {
            return null;
        }
        // 只有一个元素了
        if (inRight - inLeft == 1) {
            return new TreeNode(inorder[inLeft]);
        }
        // 后序数组postorder里最后一个即为根结点
        int rootVal = postorder[postRight - 1];
        TreeNode root = new TreeNode(rootVal);
        int rootIndex = 0;
        // 根据根结点的值找到该值在中序数组inorder里的位置
        for (int i = inLeft; i < inRight; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        // 根据rootIndex划分左右子树
        root.left = buildTree1(inorder, inLeft, rootIndex,
                postorder, postLeft, postLeft + (rootIndex - inLeft));
        root.right = buildTree1(inorder, rootIndex + 1, inRight,
                postorder, postLeft + (rootIndex - inLeft), postRight - 1);
        return root;
    }

    public static TreeNode buildTreePreIn(int[] preorder, int[] inorder) {
        return helper(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private static TreeNode helper(int[] preorder, int preLeft, int preRight,
                           int[] inorder, int inLeft, int inRight) {
        // 递归终止条件
        if (inLeft > inRight || preLeft > preRight) return null;

        // val 为前序遍历第一个的值，也即是根节点的值
        // idx 为根据根节点的值来找中序遍历的下标
        int idx = inLeft, val = preorder[preLeft];
        TreeNode root = new TreeNode(val);
        for (int i = inLeft; i <= inRight; i++) {
            if (inorder[i] == val) {
                idx = i;
                break;
            }
        }

        // 根据 idx 来递归找左右子树
        root.left = helper(preorder, preLeft + 1, preLeft + (idx - inLeft),
                inorder, inLeft, idx - 1);
        root.right = helper(preorder, preLeft + (idx - inLeft) + 1, preRight,
                inorder, idx + 1, inRight);
        return root;
    }

    /**
     * 654. Maximum Binary Tree
     * @param nums
     * @return
     */
    public static TreeNode constructMaximumBinaryTree(int[] nums) {
        return constructMaximumBinaryTree1(nums, 0, nums.length);
    }

    private static TreeNode constructMaximumBinaryTree1(int[] nums, int leftIndex, int rightIndex) {
        if (rightIndex - leftIndex < 1) {// 没有元素了
            return null;
        }
        if (rightIndex - leftIndex == 1) {// 只有一个元素
            return new TreeNode(nums[leftIndex]);
        }
        int maxIndex = leftIndex;// 最大值所在位置
        int maxVal = nums[maxIndex];// 最大值
        for (int i = leftIndex + 1; i < rightIndex; i++) {
            if (nums[i] > maxVal){
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        TreeNode root = new TreeNode(maxVal);
        // 根据maxIndex划分左右子树
        root.left = constructMaximumBinaryTree1(nums, leftIndex, maxIndex);
        root.right = constructMaximumBinaryTree1(nums, maxIndex + 1, rightIndex);
        return root;
    }

    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9);
        TreeNode root = createTreeByLevel(list);
        List<List<Integer>> listInt = levelOrder(root);
        System.out.println(listInt);
    }
}
