import csv
l = []
with open("realty (1).csv", newline='', encoding="UTF-8") as csvfile:
    sreader = csv.reader(csvfile, delimiter=',')
    for line in sreader:
        if (59.991791 >= float(line[2]) >= 59.840498) and (30.502827 >= float(line[1]) >= 30.202104):
            l.append(line)
csvfile.close()

l = sorted(l, key=lambda x: x[2])
l = map(str, l)

f = open("new_realty.txt", "w", encoding="UTF-8")
f.write('\n'.join(l))
f.close()