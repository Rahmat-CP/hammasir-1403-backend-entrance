package com.delivery.common;

public record Point(int x, int y) {

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