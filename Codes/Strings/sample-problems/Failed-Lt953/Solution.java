import java.util.*;

import java.util.AbstractList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Solution {
  public boolean isAlienSorted(String[] words, String order) {

    List<String> wordList = new AbstractList<String>() {
      @Override
      public String get(int index) {
        return words[index];
      }

      @Override
      public int size() {
        return words.length;
      }

      @Override
      public String set(int index, String element) {
        String v = words[index];
        words[index] = element;
        return v;
      }
    };

    AlienComparator alienComparator = new AlienComparator(order);
    Collections.sort(wordList, alienComparator);

    return alienComparator.isSorted;
  }
}

class AlienComparator implements Comparator<String> {
  public boolean isSorted;
  public int[] mp = new int[200];

  public AlienComparator(String orderStr) {
    isSorted = true;

    int orderLength = orderStr.length();
    for (int i = 0; i < orderLength; i++) {
      mp[(int) orderStr.charAt(i)] = i;
    }
  }

  public int compare(String x, String y) {
    // return a.name.compareTo(b.name);

    int xLength = x.length();
    int yLength = y.length();

    if (xLength == 0 && yLength != 0) {
      return -1;
    }
    if (yLength == 0 && xLength != 0) {
      isSorted = false;
      return 1;
    }

    int x0 = x.charAt(0);
    int y0 = y.charAt(0);

    if (x0 == y0) {
      return compare(x.substring(1), y.substring(1));
    }
    return mp[x0] - mp[y0];
  }
}
