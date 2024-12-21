class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(int i=0;i<bills.size();i++){
           
            if(bills[i]==5){
                five++;
            }
            
            else if(bills[i]==10){
                
                ten++;
                if(five>0){
                bills[i]-=5;
                five--;
                }
                else{return false;}
            }

            else if(bills[i]==20){
                
                if(ten>0 && five>0){

                    ten--;
                    five--;
                    bills[i]-=15;
                }
                else if( five>=3 ){
                    five-=3;
                    bills[i]-=15;
                }
                else {return false;}
             

            }
          

            if(bills[i]!=5){return false;}
            
        }
        return true;
        
    }
};