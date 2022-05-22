from PIL import Image, ImageDraw

MAX_ITER = 80
WIDTH, HEIGHT = 600, 400

# Plot window
RE_START = -2
RE_END = 1
IM_START = -1
IM_END = 1


def mandelbrot(c):
    z = 0
    n = 0
    while abs(z) <= 2 and n < MAX_ITER:
        z = z * z + c
        n += 1
    return n


if __name__ == '__main__':

    im = Image.new('HSV', (WIDTH, HEIGHT), (0, 0, 0))
    draw = ImageDraw.Draw(im)

    for x in range(0, WIDTH):
        for y in range(0, HEIGHT):
            # Convert pixel coordinate to complex number
            co_ord = complex(RE_START + (x / WIDTH) * (RE_END - RE_START),
                             IM_START + (y / HEIGHT) * (IM_END - IM_START))

            # Compute the number of iterations
            m = mandelbrot(co_ord)

            # The color depends on the number of iterations
            hue = int(255 * m / MAX_ITER)
            saturation = 255
            value = 255 if m < MAX_ITER else 0

            # Plot the point
            draw.point([x, y], (hue, saturation, value))

    im.show()
