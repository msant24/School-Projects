import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) throws FileNotFoundException {
        LinkedList list = new LinkedList();
        File file = new File("list-ops.txt");
        Scanner input = new Scanner(file);
        while(input.hasNext()){
            String command = input.next();
            if(command.equals("APPEND")){
                int value = input.nextInt();
                list.Append(value);
                System.out.println("APPEND " + value);
                System.out.println("-------------------------------------------------");
            }
            if(command.equals("ADD")){
                int index = input.nextInt();
                int value = input.nextInt();
                list.Add(index, value);
                System.out.println("ADD " + index + " " + value);
                System.out.println("-------------------------------------------------");
            }
            if(command.equals("DELETE")){
                int index = input.nextInt();
                list.Delete(index);
                System.out.println("DELETE " + index);
                System.out.println("-------------------------------------------------");
            }
            if(command.equals("SWAP")){
                int index1 = input.nextInt();
                int index2 = input.nextInt();
                list.Swap(index1, index2);
                System.out.println("SWAP " + index1 + " " + index2);
                System.out.println("-------------------------------------------------");
            }
            if(command.equals("REVERSE")){
                list.Reverse();
                System.out.println("REVERSE");
                System.out.println("-------------------------------------------------");
            }
            if(command.equals("CLEAR")){
                list.Clear();
                System.out.println("CLEAR");
                System.out.println("-------------------------------------------------");
            }
            list.Print();
            System.out.println("-------------------------------------------------");
        }
    }
}