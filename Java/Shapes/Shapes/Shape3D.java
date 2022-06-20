package Shapes;
public abstract class Shape3D implements Comparable<Shape3D> {
    private Point3D point;

    public Shape3D(int x, int y, int z) {
        point = new Point3D(x, y, z);
    }

    @Override
    public String toString() {
        return " Center=" + point.toString();
    }
    
    public double Distance(){
        double length1 = point.getZ();
        double length2 = Math.sqrt((point.getX() * point.getX()) + (point.getY() * point.getY()));
        double distance = Math.sqrt((length1 * length1) + (length2 * length2));
        return distance;
    }
    
    @Override
	public int compareTo(Shape3D s) {
		return  (int) (s.Volume() - this.Volume());
	}


    public abstract double SurfaceArea();
    
    public abstract double Volume();

    public abstract String getName();
}