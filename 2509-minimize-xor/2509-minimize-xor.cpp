class Solution {
public:
    int minimizeXor(int num1, int num2) {
       if(num1==num2)return num1;

       int cnt1=0;
       vector<int>s1(32,0);
       int temp=num1;
       int i=0;
        for (int i = 0; i < 32; ++i) {
            s1[i] = (num1 >> i) & 1;
            if(s1[i]==1)cnt1++;
        }
       int cnt2=0;
       temp=num2;
       while(temp>0){
        int bit=temp&1;
        cnt2+=bit;
        temp=temp>>1;
       }
       if(cnt1==cnt2)return num1;
       
       if (cnt1 > cnt2) {
            for (int i = 0; i < 32 && cnt1 > cnt2; i++) {
                if (s1[i] == 1) {
                    s1[i] = 0;
                    cnt1--;
                }
            }
       }
       else{
         for (int i = 0; i < 32 && cnt1 < cnt2; ++i) {
                if (s1[i] == 0) {
                    s1[i] = 1;
                    cnt1++;
                }
            }
       }


       int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (s1[i] == 1) {
                result |= (1 << i);
            }
        }

        return result;
    }
};