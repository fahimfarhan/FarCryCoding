fun main() {
    var T: Int = 0;



    // take input T
    T = readLine()!!.toInt();
    // loop for T testcases
    while(T>0) {
        T--;
        var s: String = "";
        var numOfHyphens: Int = 0;
        var numberOfUnderScores: Int = 0;
        var dontCare: Int = 0;

        dontCare = readLine()!!.toInt();

        s = readLine()!!.toString();
        // if input is --__--__---- whatever, we can convert it into -----____- format, it, the last place is always a hyphen.
        // then the subproblem becomes: you have 2 empty places, 1st place gets hyphen, 2nd place gets underscore. how many ways to do that? it?
        // (hyphen - 1)C1 * underScore C 1 == (hyphen - 1) * underScore 

        s.forEach {
            if (it == '-') {
                numOfHyphens++;
            } else if (it == '_') {
                numberOfUnderScores++;
            }
        } 

        println("numOfHyphens: $numOfHyphens, numberOfUnderScores: $numberOfUnderScores");
        // impossible cases: if numOfHyphens < 2, impossible to create the substring pattern -_-
        // if number of underscores == 0, impossible to create the substring pattern -_-
        if (numOfHyphens < 2) {
            println("0");
        } else if(numberOfUnderScores == 0) {
            println("0");
        } else {
            println("${(numOfHyphens - 1) * numberOfUnderScores}");
            // sth went wrong. I am missing some cases. need to find subsequences that contain -_-
            // if input is --__--, then the subsequences can be, -_-, --_-, ---_- .
            // input --__-_--- , output is 27. how? let's generate the set of subsequences.
            // 5 hyphen, 3 underscore, and 1 hyphen at the end.
            // ----_-, ---_-,  
        }
    }
}