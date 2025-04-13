fun main(args: Array<String>) {
    var T: Int = 0;

    var N: Int = 0;

    // take input T
    T = readLine()!!.toInt();
    // loop for T testcases
    while(T>0) {
        N = readLine()!!.toInt();
        println("${N-1}");
        T--;
    }
}