class ParkingSystem {
    int b,m,s;
    public ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    public boolean addCar(int c) {
        switch(c){
            case 1:
            if(b-1>=0){
                b--;return true;
            }return false;
            case 2:
            if(m-1>=0){
                m--;return true;
            }return false;
            case 3:
            if(s-1>=0){
                s--;return true;
            }return false;
        }
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */