// leetcode 396
// bas ek formula h woh yaad rakhna h nahi rakhenge toh bhi easy h 
// sare solutions h uska max nikalna h 
// but unme relatable yehe ki aapko bas first solution nikalna h 

// then jaise ki 
// 0 1 2 3 (multiplier)

// 4 3 2 6 (array #1)
// 6 4 3 2 (array #2)
// 2 6 4 3 (array #3)
// 3 2 6 4 (array #4)

// number of sol is equal to the length
// so first sol easily nikaldo then observe ki 4 k baad 6,2,3 pivots h 
// the formula is the currsol + array sum - (n*pivot);
// prevsol = prevsol + array sum - (n*pivot); 
// fisrt solution will be the first prevsol then traverse the loop from the end array aur but 1st position tak kyunki 0th position wala
// already aachuka h pivot mai 


class Solution {
public:
    int maxRotateFunction(vector<int>& array) {
    int n = array.size();
    int prevsol = 0; int arraysum = 0;
    for(int i=0;i<n; i++){
        prevsol = prevsol+(i*array[i]);
        arraysum = arraysum+array[i];
    }

    int maxsum = prevsol;
    for(int i=n-1; i>=1; i--){
        prevsol = prevsol + arraysum - (n*array[i]);
        if(maxsum<prevsol){
            maxsum = prevsol;
        }
    }
    return maxsum;
    }
};