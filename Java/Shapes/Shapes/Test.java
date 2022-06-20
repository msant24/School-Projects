package Shapes;

import java.util.Arrays;
import java.util.Comparator;

public class Test{
    public static void main(String[] args){
        Shape3D[] array = new Shape3D[4];
        Sphere sphere = new Sphere(2,5,8,14);
        Parallelepiped parallelepiped = new Parallelepiped(7, 16, 9, 19, 9, 13);
        Cone cone = new Cone(-5, 4, -1, 11, 15);
        Cylinder cylinder = new Cylinder(-3, -7, 5, 14, 12);
        array[0] = sphere;
        array[1] = parallelepiped;
        array[2] = cone;
        array[3] = cylinder;
        for(int i = 0; i < array.length; i++){
            System.out.println(array[i].toString());
        }
        Arrays.sort(array);
        for(int i = 0; i < array.length; i++){
            System.out.println(array[i].getName());
            System.out.println("Volume = " + array[i].Volume() + "\n\n");
        }
        Arrays.sort(array, new SortByDistance());
        for(int i = 0; i < array.length; i++){
            System.out.println(array[i].getName());
            System.out.println("Distance = " + array[i].Distance() + "\n\n");
        }
    }
}

class SortByDistance implements Comparator<Shape3D>{

    @Override
    public int compare(Shape3D o1, Shape3D o2) {
        if(o1.Distance() < o2.Distance()) return -1;
        if(o1.Distance() > o2.Distance()) return 1;
        else return 0;
    }
    
}