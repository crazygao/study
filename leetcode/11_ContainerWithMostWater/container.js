/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var _oneLineMaxArea = function(_height, index) {
        var areaArray = _height.filter((num, i) => (i > index)).map((num, i) => {
            return Math.min(_height[index], num) * (i + 1);
        });
        return Math.max(...areaArray);
    }
    var maxArea = height.map((num, i) => {
        return _oneLineMaxArea(height, i);
    });
    return Math.max(...maxArea);
};
