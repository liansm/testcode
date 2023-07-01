
function is_conflict(r, r_val, j, j_val) {
    if (r_val == j_val) {
        return true;
    }
    if (j - r == j_val - r_val || j - r == r_val - j_val) {
        return true;
    }
    return false;
}

function can_put(row, value, cur_queens) {
    var queen_size = cur_queens.length;
    for (var i = 0; i < queen_size; ++i) {
        if (is_conflict(row, value, i + 1, cur_queens[i])) {
            return false;
        }
    }
    return true;
}


function print_queens(cur_queens) {
    var queen_size = cur_queens.length;
    var str = "[" + total_solution + "]";
    for (var i = 0; i < queen_size; ++i) {
        str += cur_queens[i] + "\t";
    }
    console.log(str);
}

function backtrace(cur_queens, max_queen_size) {
    var queen_size = cur_queens.length;
    for (var i = 1; i <= max_queen_size; ++i) {
        if (can_put(queen_size + 1, i, cur_queens)) {
            cur_queens.push(i)
            if (cur_queens.length == max_queen_size) {
                ++total_solution;
                print_queens(cur_queens);
            }
            backtrace(cur_queens, max_queen_size);
        }
    }

    if (cur_queens.length != 0) {
        cur_queens.pop();
    }
}


var max_queen_size = 8;
var total_solution = 0;
var cur_queens = [];

backtrace(cur_queens, max_queen_size);

console.log("Total Solutions: " + total_solution);


