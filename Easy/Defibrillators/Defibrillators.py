from math import radians, cos, hypot

lon, lat, closest = radians(float(input().replace(',', '.'))), radians(float(input().replace(',', '.'))), (float('inf'), '')

for i in range(int(input())):
    defib = list(input().split(';'))
    defib_lon, defib_lat = radians(float(defib[4].replace(',', '.'))), radians(float(defib[5].replace(',', '.')))
    distance = hypot((defib_lon - lon) * cos((lat + defib_lat) / 2), defib_lat - lat) * 6371
    closest = (distance, defib[1]) if distance <= closest[0] else closest
    
print(closest[1])