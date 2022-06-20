import java.util.Random;

public class Pile {
    int pile;

    public Pile() {
        Random rand = new Random();
        pile = rand.nextInt(100 - 10 + 1) + 10;
    }

    public void TakeMarbles(int num){
        pile = pile - num;
    }
    public int getPile(){
        return pile;
    }
}