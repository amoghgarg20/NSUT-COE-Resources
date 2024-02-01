df <- read.csv("D:/NSUT Work/CHS/Iris.csv", header = TRUE)
df
View(df)
y <- table(df$Species)
barplot(y, horiz = TRUE ,col = c("red","green","blue"), border = NA, main = "Frequency Distribution")
hist(df$SepalLengthCm, main = "Sepal-Length", col = "beige", xlab = "Bins")
pairs(~SepalLengthCm + SepalWidthCm + PetalLengthCm + PetalWidthCm, data = df)
