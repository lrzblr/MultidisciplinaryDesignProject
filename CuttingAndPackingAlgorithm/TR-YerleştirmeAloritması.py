import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches

def place_rectangles_advanced(rectangles, area_width, area_height):
    """
    Daha gelişmiş bir yerleştirme algoritması kullanarak dikdörtgenleri yerleştirmeye çalışır.
    """
    placed_rectangles = []
    space_matrix = np.zeros((area_height, area_width), dtype=int) 

    for index, (width, height) in enumerate(rectangles):
        for y in range(area_height - height + 1):
            for x in range(area_width - width + 1):
                if not np.any(space_matrix[y:y+height, x:x+width]):
                    placed_rectangles.append((x, y, width, height))
                    space_matrix[y:y+height, x:x+width] = index + 1
                    break
            if len(placed_rectangles) > index:
                break

    return placed_rectangles

def calculate_rectangle_edges(rectangles):
    """
    Verilen dikdörtgenlerin sol alt ve sağ üst köşe koordinatlarını hesaplar.
    """
    x1_values = []
    y1_values = []
    x2_values = []
    y2_values = []

    for (x, y, width, height) in rectangles:
        x1_values.append(x)
        y1_values.append(y)
        x2_values.append(x + width)
        y2_values.append(y + height)

    return x1_values, y1_values, x2_values, y2_values

def draw_rectangles(rectangles, area_width, area_height):
    """
    Yerleştirilmiş dikdörtgenleri görselleştiren bir PNG dosyası oluşturur.
    """
    fig, ax = plt.subplots()
    ax.set_xlim(0, area_width)
    ax.set_ylim(0, area_height)
    ax.set_aspect('equal')

    for (x, y, width, height) in rectangles:
        rect = patches.Rectangle((x, y), width, height, edgecolor='blue', facecolor='lightblue')
        ax.add_patch(rect)

    plt.gca().invert_yaxis()
    plt.savefig("C:\\...\\...\\...\\...\\...\\placed_rectangles.png") //Noktalı alanları değiştirin, kullanmak için

# Dosya okuma yolu
file_path = "C:\\...\\...\\...\\...\\...\\C1_1.txt" // Noktalı alanları değiştirin, kullanmak için
with open(file_path, 'r') as file:
    contents = file.readlines()

num_rectangles = int(contents[0].strip())
area_width, area_height = map(int, contents[1].strip().split())
rectangles = [tuple(map(int, line.strip().split())) for line in contents[2:]]

placed_rectangles = place_rectangles_advanced(rectangles, area_width, area_height)
x1, y1, x2, y2 = calculate_rectangle_edges(placed_rectangles)

draw_rectangles(placed_rectangles, area_width, area_height)

# C dizisi formatında çıktı
output_txt_path = "C:\\...\\...\\...\\...\\...\\rectangle_edges.txt" //Noktalı alanları değiştirin, kullanmak için
with open(output_txt_path, 'w') as file:
    file.write("obj_x1[] = {" + ", ".join(map(str, x1)) + "}; // X1 değerleri Sol alt köşe\n")
    file.write("obj_y1[] = {" + ", ".join(map(str, y1)) + "}; // Y1 değerleri\n")
    file.write("obj_x2[] = {" + ", ".join(map(str, x2)) + "}; // X2 değerleri Sağ üst köşe\n")
    file.write("obj_y2[] = {" + ", ".join(map(str, y2)) + "}; // Y2 değerleri\n")