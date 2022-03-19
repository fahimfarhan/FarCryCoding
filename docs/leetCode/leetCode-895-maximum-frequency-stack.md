## Approach 1: Stack of Stacks

## Intuition

Evidently, we care about the frequency of an element. Let freq be a Map from xx to the number of occurrences of xx.

Also, we (probably) care about maxfreq, the current maximum frequency of any element in the stack. This is clear because we must pop the element with the maximum frequency.

The main question then becomes: among elements with the same (maximum) frequency, how do we know which element is most recent? We can use a stack to query this information: the top of the stack is the most recent.

To this end, let group be a map from frequency to a stack of elements with that frequency. We now have all the required components to implement FreqStack.

## Algorithm

Actually, as an implementation level detail, if x has frequency f, then we'll have x in all group[i] (i <= f), not just the top. This is because each group[i] will store information related to the ith copy of x.

Afterwards, our goal is just to maintain freq, group, and maxfreq as described above.

## Code (Original solution in java)
```java
class FreqStack {
    Map<Integer, Integer> freq;
    Map<Integer, Stack<Integer>> group;
    int maxfreq;

    public FreqStack() {
        freq = new HashMap();
        group = new HashMap();
        maxfreq = 0;
    }

    public void push(int x) {
        int f = freq.getOrDefault(x, 0) + 1;
        freq.put(x, f);
        if (f > maxfreq)
            maxfreq = f;

        group.computeIfAbsent(f, z-> new Stack()).push(x);
    }

    public int pop() {
        int x = group.get(maxfreq).pop();
        freq.put(x, freq.get(x) - 1);
        if (group.get(maxfreq).size() == 0)
            maxfreq--;
        return x;
    }
}
```

## Code (My implementation in C++)
```cpp
class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int> > group;
    int maxFreq = 0;
    FreqStack() {
      maxFreq = 0;
    }

    int getFrequencyOrDefault(const int& input, const int& defaultValue) {
      auto output = freq.find(input);
      if( output == freq.end() ) {
        return defaultValue;
      }
      return output->second;
    }

    void computeIfAbsentAndPush(const int& val, const int& freq) {
      auto p = group.find(freq);
      if( p == group.end() ) {
        stack<int> temp;
        temp.push(val);
        group[freq] = temp;
      } else {
        p->second.push(val);
      }
    }

    void push(int val) {
        int oldf = getFrequencyOrDefault(val, 0);
        int newf = oldf+1;
        freq[val] = newf;
        
        if(newf > maxFreq) {
          maxFreq = newf;
        }
        computeIfAbsentAndPush(val, newf);
    }
    
    int pop() {
      int x = group[maxFreq].top();
      group[maxFreq].pop();

      freq[x] = freq[x] - 1;
      if(group[maxFreq].size() == 0) {
        maxFreq--;
      }
      return x;
    }
};

```

## Complexity Analysis

* Time Complexity: O(1)O(1) for both push and pop operations.

* Space Complexity: O(N)O(N), where N is the number of elements in the FreqStack.