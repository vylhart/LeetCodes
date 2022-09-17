/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, h= 10005;
        while(l<=h){
            int m = (l+h)/2;
            if(reader.get(m)==target){
                return m;
            }
            else if(reader.get(m)<target){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return -1;
    }
};