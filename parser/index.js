const puppeteer = require('puppeteer');
const fs = require('fs');

setInterval(async () => {
    const browser = await puppeteer.launch({ headless: true });
    const page = await browser.newPage();
    await page.goto('https://www.bsb.by/kalkulyator-valyut');
    for (let i = 0; i < 14; i++) {
        let arr = await page.evaluate((index) => {
            let element = document.querySelectorAll('.custom-table__tbody-tr')[index].childNodes[1].innerText;
            return element;
        }, i);
        fs.appendFileSync('text.txt', arr + ' | ');
        let arr1 = await page.evaluate((index) => {
            let element = document.querySelectorAll('.custom-table__tbody-tr')[index].childNodes[2].innerText;
            return element;
        }, i);
        fs.appendFileSync('text.txt', arr1 + ' | ');
        let arr2 = await page.evaluate((index) => {
            let element = document.querySelectorAll('.custom-table__tbody-tr')[index].childNodes[3].innerText;
            return element;
        }, i);
        fs.appendFileSync('text.txt', arr2 + '\n');
    }
    await browser.close();
}, 10000);
