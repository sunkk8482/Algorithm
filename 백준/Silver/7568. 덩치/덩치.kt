fun main() {
    val count = readln().toInt()
    val inputArray = Array(count) { readln().split(' ').map { it.toInt() } }

    val output = StringBuilder()
    for (i in inputArray) {
        var num = 1
        for(j in inputArray) {
            if(j[0] > i[0] && j[1] > i[1]) num++
        }
        output.append(num).append(' ')
    }
    println(output)
}