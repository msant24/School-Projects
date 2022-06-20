package Shapes;

public class Cylinder extends Shape3D{

    double radius, height;
    String name = "Cylinder";

    public Cylinder(int x, int y, int z, double radius, double height) {
        super(x, y, z);
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double SurfaceArea() {
        double area = 2 * Math.PI * radius * radius + 2 * Math.PI * radius * height;
        return area;
    }

    @Override
    public double Volume() {
        double volume = Math.PI * radius * radius * height;
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