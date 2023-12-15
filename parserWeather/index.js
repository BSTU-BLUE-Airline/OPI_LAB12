const puppeteer = require('puppeteer');
const fs = require('fs');

setInterval(async () => {
    const browser = await puppeteer.launch({ headless: false });
    const page = await browser.newPage();

    for (let x = 0; x < 20; x++) {
        await page.goto('https://www.accuweather.com/ru/world-weather/');
        let arr = await page.evaluate((index) => {
            let element = document.querySelectorAll('.nearby-location')[index].childNodes[1].innerText;
            return element;
        }, x);
        fs.appendFileSync('text.txt', arr + ' | ');
        let arr1 = await page.evaluate((index) => {
            let element = document.querySelectorAll('.nearby-location')[index].childNodes[5].innerText;
            return element;
        }, x);
        fs.appendFileSync('text.txt', arr1 + '\n');
    }

    await browser.close();
}, 1800000);