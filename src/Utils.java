import java.util.ArrayList;
import java.util.List;

public class Utils {

    public static int[] listToArray(List<Integer> tree) {
        int[] ret = new int[tree.size()];
        for (int i = 0; i < tree.size(); ++i)
            ret[i] = tree.get(i);
        return ret;
    }


    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < 10; ++i)
            list.add(i);
        int[] ret = listToArray(list);
        for (int i : ret)
            System.out.println(i);
    }
}
