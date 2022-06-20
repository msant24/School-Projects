package Shapes;

public class Parallelepiped extends Shape3D{

    double length, width, height;
    String name = "parallelepiped";
    public Parallelepiped(int x, int y, int z, double length, double width, double height) {
        super(x, y, z);
        this.length = length;
        this.width = width;
        this.height = height;
    }

    @Override
    public double SurfaceArea() {
        double area = 2.0*(length * width) + 2.0*(width * height) + 2.0*(height * length);
        return area;
    }

    @Override
    public double Volume() {
        double volume = length * width * height;
        return volume;
    }

    @Override
    public String toString() {
        return name + super.toString() + "\nlength= " + length + "\nwidth= " + width + "\nheight= " + height + "\nSurfaceArea= " + SurfaceArea() + "\n\n";
    }
    
    public String getName(){
        return name;
    }
    
}