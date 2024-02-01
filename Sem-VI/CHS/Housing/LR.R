data <- read.csv("D:/NSUT Work/CHS/Housing/Housing.csv")

set.seed(123) # for reproducible results
sample.size <- floor(0.7 * nrow(data))
train.index <- sample(seq_len(nrow(data)), size = sample.size)
train <- data[train.index, ]
test <- data[- train.index, ]

lm.fit = lm(price ~ ., data = train) # fit a simple linear regression model
summary(lm.fit)

predictions <- predict(lm.fit,test)
errors <- predictions - test$price
mean_error <- mean(abs(errors))

# Plot the results
library(ggplot2)
ggplot(data, aes(x = area, y = price)) +
  geom_point() +
  geom_smooth(method = "lm") +
  labs(title = "Linear Regression Model", x = "Area", y = "Price") +
  theme_bw()

