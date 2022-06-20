package Shapes;

public class Sphere extends Shape3D{

    double radius;
    String name = "Sphere";

    public Sphere(int x, int y, int z, double radius) {
        super(x, y, z);
        this.radius = radius;
    }

    @Override
    public double SurfaceArea() {
        double area = 4 * Math.PI * radius * radius;
        return area;
    }

    @Override
    public double Volume() {
        double volume = (4/3) * Math.PI * radius * radius * radius;
        return volume;
    }

    @Override
    public String toString() {
        return name + super.toString() + "\nRadius= " + radius + "\nSurfaceArea= " + SurfaceArea() + "\n\n";
    }
    public String getName(){
        return name;
    }

    
}