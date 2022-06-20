package Shapes;

public class Cone extends Shape3D{

    double radius, height;
    String name = "Cone";

    public Cone(int x, int y, int z, double radius, double height) {
        super(x, y, z);
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double SurfaceArea() {
        double area = (Math.PI * radius * radius * height)/3;
        return area;
    }

    @Override
    public double Volume() {
        double volume = Math.PI * radius * (radius + Math.sqrt((radius * radius) + (height * height)));
        return volume;
    }

    @Override
    public String toString() {
        return name + super.toString() + "\nRadius= " + radius + "\nHeight= " + height + "\nSurfaceArea= " + SurfaceArea() + "\n\n";
    }
    public String getName(){
        return name;
    }
    
}