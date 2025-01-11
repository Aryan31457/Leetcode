class Solution {
public:

    string mul(string &num1,char x){
        string ans;
        int carry=0;
        int i=0;
        int m=x-'0';
        while(i<num1.size()){
            int dig=num1[i]-'0';
            dig= (dig*m)+carry;
            carry=dig/10;
            ans+=(dig%10 +'0');
            i++;
        }
        if(carry>0){
            ans.push_back(carry+'0');
        }
        return ans;
    }

    string sum(string &num1, string &num2){
    int i=num1.size()-1,j=num2.size()-1;
        string ans;
        int carry=0;
         while (i >= 0 || j >= 0 || carry > 0) { 
            int a = (i >= 0) ? num1[i--] - '0' : 0; 
            int b = (j >= 0) ? num2[j--] - '0' : 0; 
            int dig = (a + b + carry) % 10; 
            carry = (a + b + carry) / 10; 
            ans.push_back(dig + '0'); 
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        vector<string>results;
        string zero="";
        for(int i=0;i<num2.size();i++){
            string temp=mul(num1,num2[i]);
            reverse(temp.begin(),temp.end());
            results.push_back((temp+zero));
            zero+="0";
        }
        reverse(results.begin(), results.end());

        string sumi="0";
        
        for(int i=0;i<results.size();i++){
               
            sumi=sum(sumi,results[i]);
           
        }
        return sumi;
        




        
    }
};