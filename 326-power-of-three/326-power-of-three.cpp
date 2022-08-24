class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        return (ceil(log10(n)/log10(3))==floor(log10(n)/log10(3)));
    }
};

/*class Solution {
public:
    bool isPowerOfThree(int n)
    {
      if(n==0)return false;

      double a=log10(n)/log10(3);

      if(ceil(a)==floor(a))
          return true;

      return false;
    }
};*/