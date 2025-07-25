public final class Point {
    private final int x;
    private final int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    /**
     * @param other The other point.
     * @return The distance.
     */
    public double distanceTo(Point other) {
        if (other == null) {
            return 0.0;
        }
        // Math.hypot calculates sqrt(x*x + y*y) without intermediate overflow or underflow.
        return Math.hypot(this.x - other.x, this.y - other.y);
    }
}