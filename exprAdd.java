/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

public List<String> addOperators(String num, int target) {
    List<String> all = new ArrayList<String>();
    dfs(num, 0, target, 0, 0, "", all);
    return all;
}
private void dfs(String num, int pos, int target, long curSum,
                long preSum, String exp, List<String> all) {
    if (pos == num.length() && curSum == target) {
        all.add(exp);
        return;
    }
    for (int i = pos; i < num.length(); i++) {
        String s = num.substring(pos, i+1);
        long v = Long.parseLong(s);
        if (exp.isEmpty()) {
            dfs(num, i+1, target, curSum+v, curSum, s, all);
        } else {
            dfs(num, i+1, target, curSum+v, curSum, exp+"+"+s, all);
            dfs(num, i+1, target, curSum-v, curSum, exp+"-"+s, all);
            dfs(num, i+1, target, (curSum-preSum)*v+preSum, preSum, exp+"*"+s, all);
        }
        if (num.charAt(pos) == '0')
            return;
    }
}
