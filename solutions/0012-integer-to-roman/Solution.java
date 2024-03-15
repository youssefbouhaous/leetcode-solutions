class Solution {
    public String intToRoman(int n) {
        Map<Integer,String>d = new HashMap<Integer,String>();
        if(n==4){
            return "IV";
        }
        if(n==9){
            return "IX";
        }
        if(n==40){
            return "XL";
        }
        if(n==90){
            return "XC";
        }
        if(n==400){
            return "CD";
        }
        if(n==900){
            return "CM";
        }
        d.put(1,"I");
        d.put(5,"V");
        d.put(10,"X");
        d.put(50,"L");
        d.put(100,"C");
        d.put(500,"D");
        d.put(1000,"M");
        String ans="";
        while(n>0){
            
            if(n>=1000){
                n-=1000;
                ans=ans+d.get(1000);
            }
            else if(n>=900){
                ans+= "CM";
                n-=900;
            }
            else if(n>=500){
                n-=500;
                ans=ans+d.get(500);
            }
            else if(n>=400){
                ans+= "CD";
                n-=400;
            }
            else if(n>=100){
                n-=100;
                ans=ans+d.get(100);
            }
            else if(n>=90){
                ans+= "XC";
                n-=90;
            }
            else if(n>=50){
                n-=50;
                ans=ans+d.get(50);
            }
            else if(n>=40){
                ans+= "XL";
                n-=40;
            }
            else if(n>=10){
                n-=10;
                ans=ans+d.get(10);
            }
            else if(n>=9){
                ans+= "IX";
                n-=9;
            }
            else if(n>=5){
                n-=5;
                ans=ans+d.get(5);
            }
            else if(n>=4){
            ans+= "IV";
            n-=4;
            }
            else if(n>=1){
                n-=1;
                ans=ans+d.get(1);
            }
        }
        return ans;
    }
}