
<details dir='rtl' open><summary><h2>شرح سوال</h2></summary>

  شرکتی نوپا قصد دارد سامانه‌ای در زمینه ارسال مرسولات طراحی کند که فعلا شامل سه روش پیک موتوری درون شهری، پیک سواری درون شهری و باربری برون شهری است. با توجه به نیاز فوری به داشتن این سامانه قرار است در ابتدا ۳ تیم همزمان روی این پروژه کار کنند. شما وظیفه تکمیل پیاده‌سازی بخش‌هایی از پیک موتوری درون شهری را بر عهده دارید.

# جزئیات پروژه

### گام اول: کلاس‌های `Parcel` و `ParcelBuilder`

در اولین گام شما باید کلاسی با نام `Parcel` را ایجاد کنید. این کلاس قرار است اطلاعات مرسوله را شامل شود و دارای مشخصات زیر است:

| نام            | نوع     | توضیح         |
| -------------- | ------- | ------------- |
| weight         | int     | وزن           |
| length         | int     | طول           |
| width          | int     | عرض           |
| isFlammable     | boolean | قابلیت اشتعال |
| isChemical     | boolean | شیمیایی بودن  |
| source         | Point   | مبدا          |
| destination    | Point   | مقصد          |
| insurancePrice | int     | مبلغ بیمه     |

کلاس `Point` شامل مشخصات زیر است:

| نام    | نوع    | توضیح         |
| ------ | ------ | ------------- |
| x      | int    | طول جغرافیایی |
| y      | int    | عرض جغرافیایی |

کلاس `Parcel`  باید دارای متد `builder` باشد. این متد، یک متد استاتیک است که باید یک شئ از کلاس `ParcelBuilder` را برگرداند. 

کلاس `ParcelBuilder` وظیفه ایجاد راحت‌تر اشیا کلاس `Parcel` را برعهده دارد. مثلا به ساختار زیر دقت کنید:

<details dir='ltr'><summary>java</summary>
  
```java
public class Item {
    static ItemBuilder builder() {}

    class ItemBuilder {
        Item build() {}
    }
}
```
</details>

<details dir='ltr' open><summary>cpp</summary>

```cpp
class Item {
public:
    static class ItemBuilder builder() {
        return ItemBuilder();
    }

    class ItemBuilder {
    public:
        Item build() {
            return Item();
        }
    };
};
```
</details>

<details dir='ltr'><summary>python</summary>

```python
class Item:
    @staticmethod
    def builder():
        return Item.ItemBuilder()

    class ItemBuilder:
        def build(self):
            return Item()
```
</details>

مشابه ساختار بالا شما می‌توانید کلاس `ParcelBuilder` را طوری پیاده‌سازی کنید تا بتوان به وسیله متد `build` آن، شئ از کلاس `Parcel` ایجاد نمود. به عنوان مثال کد زیر را در نظر بگیرید:

```java
Point sourcePoint = new Point(10, 10);
Point destinationPoint = new Point(20, 20);

Pracel parcel = Pracel.builder()
	.weight(100)
	.length(50)
	.width(20)
	.isFlamable(false)
	.isChemical(false)
	.source(sourcePoint)
	.destination(destinationPoint)
	.insurancePrice(20000000)
	.build();
```
### گام دوم: چهارچوب برنامه

برای اینکه سه تیم بطور همزمان بتوانند کار کنند قواعدی را مشخص می کنیم تا سه تیم از یک قاعده استفاده کنند برای این منظور توابع زیر مشخص شده است که هر سه تیم باید آن ها را پیاده کند.
```java
int calculatePrice(Parcel  parcel);
void checkConditions(Parcel parcel);
```
همچنین این شرکت قصد دارد تا قابلیت ارسال فوری را به پیک موتوری درون شهری و پیک خودرو سواری درون شهری اضافه کند. 

**دقت کنید** که این ویژگی برای حمل و نقل برون شهری **قابل ارائه نیست**، بنابراین نیاز است تا قاعده‌ای مشخص شود که فقط دو تیم مربوط به حمل و نقل درون شهری ملزم به رعایت آن باشند. برای این منظور علاوه بر توابع قبلی یک تابع دیگر مشخص شده است.
```java
int calculatePrice(Parcel parcel, boolean fastDelivery);
```
### گام سوم: پیاده سازی `Configuration`

در این گام می‌خواهیم که مقادیر ثابت برنامه به جای اینکه در خود کلاس‌ها تعریف شوند، در یک کلاس به نام تنظیمات تعریف شده، مقداردهی شوند و در سایر قسمت‌ها مورد استفاده قرار گیرند. مقداردهی این کلاس در شروع برنامه به طور خودکار انجام می‌شود.

شما کلاس `Configuration` را به گونه‌ای پیاده‌سازی کنید که فقط بتوان یک نمونه از آن به ازای کل برنامه ایجاد شود. به عبارت دیگر امکان ایجاد فقط یک نمونه از این کلاس در حافظه وجود داشته باشد و در صورت نمونه‌سازی همان شی قبلی برگشت داده شود.

کلاس `Configuration` شامل مقادیر زیر می باشد:

| نام            | نوع    | توضیح                                   |
| -------------- | ------ | --------------------------------------- |
| basePrice      | int    | قیمت پایه حمل مرسوله                    | 
| unitPrice      | int    | قیمت واحد حمل مرسوله به ازای هر واحد فاصله |
| weightLimit    | int    | حداکثر وزن مجاز مرسوله                  |
| dimensionLimit | int    | حداکثر ابعاد مجاز مرسوله                |

### گام چهارم: پیاده سازی کلاس `BikeDelivery`

کلاس `BikeDelivery` را مطابق با چهارچوب کلی برنامه به گونه ای پیاده‌سازی کنید که اگر در قواعد تغییراتی رخ داد ملزم به پیاده‌سازی آن باشد.

نحوه محاسبه قیمت برای این حمل و نقل به صورت زیر است:

`price = (unitPrice * distance) + basePrice + (%10  * insurancePrice);`

هم‌چنین نحوه محاسبه قیمت برای تحویل فوری به صورت زیر خواهد بود:

`price = (unitPrice * distance) + basePrice + (%10 * insurancePrice)  + (10٪  *‌ (unitPrice * distance))`

**دقت کنید** که برای این پارامتر‌ها باید از کلاس `Configuration` استفاده کنید. به عنوان مثال نحوه استفاده از `configuration` در محاسبه قیمت به شکل زیر خواهد بود:

`price = configuration.getUnitPrice() * distance + configuration.getBasePrice() + %1 * insurancePrice  + 10٪  *‌ (unitPrice * distance)`

هرکدام از این مقادیر به صورت زیر است:

| نام       | توضیح                                                              |
| --------- | ------------------------------------------------------------------ |
| unitPrice | قیمت واحد حمل مرسوله، به ازای هر واحد فاصله، مقدار ثابت 1000 تومان است |
| distance  | فاصله اقلیدسی بین source و destination                             |
| basePrice | هزینه پایه ارسال مرسوله، مقدار ثابت 1000 تومان است       |

### گام پنجم: پیاده‌سازی `checkConditions`

همیشه پیش از تایید ارسال مرسوله شرایط آن شامل ابعاد، وزن، قابلیت اشتعال و شیمیایی بودن بررسی می‌شود. در هریک از روش‌های ارسال، شرایط و ترتیب چک کردن می‌تواند متفاوت باشد. به عنوان مثال در حمل و نقل برون شهری باید ابتدا ابعاد، سپس وزن و در آخر قابلیت اشتعال چک شود، اگر هر یک از شرایط قابل قبول نباشد فرآیند متوقف شده و در خروجی پیامی چاپ می‌شود که مشخص می‌کند کدام شرط غیر مجاز بوده است. 

قطعه کد‌ زیر نحوه بررسی شرایط برای حمل و نقل برون شهری را نشان می‌دهد:

<details dir='ltr'><summary>java</summary>
	
```java
public void checkConditions(Parcel parcel) {
	Checker dimensionChecker = new DimensionChecker();
	Checker weightChecker = new WeightChecker();
	Checker flamableChecker = new FlamableChecker();

	dimensionChecker.setNextChecker(weightChecker);
	weightChecker.setNextChecker(flamableChecker);

	dimensionChecker.check(parcel);
}
```
</details>

<details dir='ltr' open><summary>cpp</summary>
	
```cpp
void checkConditions(Parcel parcel) {
    Checker* dimensionChecker = new DimensionChecker();
    Checker* weightChecker = new WeightChecker();
    Checker* flamableChecker = new FlamableChecker();

    dimensionChecker-&gt;setNextChecker(weightChecker);
    weightChecker-&gt;setNextChecker(flamableChecker);

    dimensionChecker-&gt;check(parcel);
}

```
</details>

<details dir='ltr'><summary>python</summary>

```python
def check_conditions(self, parcel):
    dimension_checker = DimensionChecker()
    weight_checker = WeightChecker()
    flamable_checker = FlamableChecker()

    dimension_checker.set_next_checker(weight_checker)
    weight_checker.set_next_checker(flamable_checker)

    dimension_checker.check(parcel)

```
</details>

همان‌طور که مشاهده کردید، در متد `checkConditions` ابتدا کلاس‌های `checker` برای بررسی شرایط مختلف که پیش‌تر ذکر شد، ایجاد شده است. سپس، ترتیب چک شدن شروط تعیین شده و در آخر با فراخوانی متد `check` از `dimensionChecker` تمام شروط به ترتیب بررسی شده و در صورت غیر مجاز بودن هر یک از شروط فرآیند متوقف شده و پیامی در خروجی چاپ می‌شود که مشخص می‌کند کدام شرط غیر مجاز بوده است.

با در نظر گرفتن پیاده‌سازی ارائه شده در `checkConditions` کلاس‌های `Checker` و `WeightChecker` را پیاده‌سازی کنید.

**مفروضات:** وزن مجاز برای مرسوله 10 کیلوگرم و کمتر می باشد.

# نکات

+ این سوال را می‌توانید با سه زبان `Java`، `C++` و `Python` حل و برای داوری ارسال کنید.
+ در صورتی که از زبان `C++` استفاده می‌کنید باید هدر فایل‌ها را به درستی و مطابق صورت سوال ایجاد و برای داوری ارسال کنید.
+ تمام موارد گفته شده در صورت سوال برای سه زبان یکسان است و شما باید این موارد را به درستی پیاده‌سازی کنید.
+ **دقت کنید** که نام کلاس‌هایی که ایجاد می‌کنید کاملا مطابق صورت سوال باشد.
+ امتیاز‌دهی این سوال توسط تیم داوری انجام خواهد شد و برای داوری این سوال موارد مختلفی از جمله تمیز بودن کد، درک شما از مسئله، پیاده‌سازی و راه‌حل به کار رفته توسط شما مورد ارزیابی قرار خواهد گرفت.
+ **توجه کنید** که آخرین ارسال شما برای این سوال داوری خواهد شد و نتیجه بعد از مسابقه اعلام می‌شود.

# آن‌چه باید آپلود کنید

پس از پیاده‌سازی موارد خواسته‌شده، پروژه خود را با فرمت `ZIP` ارسال کنید.

</details>
