/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
  const a = s.trim().split(' ');
  const l = a.length;
  
  if (l) {
    return a[l -1].length;
  } else {
    return 0;
  }
};
