/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int solve(int target,MountainArray &arr,int s,int e,bool inc){
        
        while(s<=e){
            int mid=(s+e)/2;

            int midval=arr.get(mid);
            if(midval==target){
                return mid;
            }
            else if(midval<target){
                if(inc){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            else{
                if(inc){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
        }
        return -1;

    }
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int peak=-1;
        int s=0,e=arr.length()-1;
        while(s<=e){
            int mid=(s+e)/2;

            int curr=arr.get(mid);
            int next=arr.get(mid+1);
            if(curr<next){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        peak=s;

        if(arr.get(peak)==target)return peak;
        
        int find=solve(target,arr,0,peak,true);
        if(find!=-1){return find;}

        return solve(target,arr,peak,arr.length()-1,false);


    }
};