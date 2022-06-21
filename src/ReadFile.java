import sun.util.locale.provider.JRELocaleProviderAdapter;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Character.isDigit;

public class ReadFile {

    public static List<List<Integer>> readFileToList(String filePath) {
        List<List<Integer>> ret = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))){
            String line;
            ArrayList<Integer> list;

            while ((line = br.readLine()) != null) {
                list = strTOList(line);
                ret.add(list);
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
//        System.out.println(ret);
        return ret;
    }

    public static ArrayList<Integer> strTOList(String line) {
        ArrayList<Integer> listTree = new ArrayList<>();
        String strInt = "";
        for (int i = 0; i < line.length(); ++i) {
            if (isDigit(line.charAt(i))) {
                strInt += String.valueOf(line.charAt(i));
            } else {
                if (strInt.length() != 0) {
                    listTree.add(strTOInteger(strInt));
                    strInt = "";
                }
            }
        }

        return listTree;
    }

    public static Integer strTOInteger(String str) {
        Integer ret = 0;
        for (int i = 0; i < str.length(); ++i) {
            Integer num = str.charAt(i) - '0';
            ret = ret * 10 + num;
        }
        return ret;
    }

    public static void main(String[] args) {
        String filePath = "C:\\Users\\lenovo\\Desktop\\strTrees.txt";
        readFileToList(filePath);
    }
}
