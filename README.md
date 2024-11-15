# Ice Cream Sales Analysis Dashboard 🍦

A web-based dashboard for analyzing ice cream parlor sales data. This application provides visual and numerical insights into sales patterns, popular items, and revenue metrics.

## 🚀 Features

- **File Upload**: Easy CSV data import functionality
- **Interactive Charts**: Visual representation of sales data using Recharts
- **Comprehensive Analysis**:
  - Total store sales
  - Month-wise sales totals
  - Most popular items by month
  - Highest revenue items by month
  - Statistical analysis of popular items

## 📋 Prerequisites

- Node.js (v14 or higher)
- npm or yarn package manager

## 🛠️ Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/ice-cream-sales-analysis.git
cd ice-cream-sales-analysis
```

2. Install dependencies:
```bash
npm install
# or
yarn install
```

3. Start the development server:
```bash
npm run dev
# or
yarn dev
```

## 📊 Data Format

The application expects CSV files with the following columns:
```
Date,Item,Quantity,Price
2024-01-01,Vanilla Cone,10,3.99
```

- **Date**: YYYY-MM-DD format
- **Item**: Product name
- **Quantity**: Number of units sold
- **Price**: Unit price

## 🚀 Deployment

### Deploying to Netlify

1. Create a Netlify account at [netlify.com](https://www.netlify.com)

2. Install Netlify CLI:
```bash
npm install netlify-cli -g
```

3. Build the project:
```bash
npm run build
```

4. Deploy using one of these methods:

   a. **Git-based deployment**:
   - Connect your GitHub repository in the Netlify dashboard
   - Configure build settings:
     - Build command: `npm run build`
     - Publish directory: `dist`

   b. **Manual deployment**:
   ```bash
   netlify deploy --prod
   ```

   c. **Drag-and-drop**:
   - Drag the `dist` folder to Netlify's upload area

## 🔧 Configuration

Create a `.env` file in the root directory:
```
VITE_APP_TITLE=Ice Cream Sales Analysis
```

## 📝 Usage

1. Launch the application
2. Click "Upload CSV" to import your sales data
3. View generated analytics in the dashboard
4. Export or share results using the built-in tools

## 🎨 Customization

### Styling
The application uses Tailwind CSS for styling. Modify `tailwind.config.js` to customize:
- Color schemes
- Typography
- Layout properties

### Charts
Adjust chart configurations in `src/components/Charts/`:
- Chart types
- Color schemes
- Data visualization options

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch:
```bash
git checkout -b feature/amazing-feature
```
3. Commit changes:
```bash
git commit -m 'Add amazing feature'
```
4. Push to the branch:
```bash
git push origin feature/amazing-feature
```
5. Open a Pull Request

## 📜 License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## 👥 Support

For support, email support@example.com or open an issue in the repository.

## 🙏 Acknowledgments

- [React](https://reactjs.org/)
- [Recharts](https://recharts.org/)
- [Tailwind CSS](https://tailwindcss.com/)
- [shadcn/ui](https://ui.shadcn.com/)

## 📈 Roadmap

- [ ] Add export functionality
- [ ] Implement data caching
- [ ] Add more chart types
- [ ] Include predictive analytics
- [ ] Add user authentication

## ⚠️ Known Issues

- Large CSV files (>50MB) may cause performance issues
- Safari browser has limited chart interaction features

## 🔄 Version History

* 0.2.0
    * Add chart animations
    * Improve mobile responsiveness
* 0.1.0
    * Initial Release

## 📝 Project Structure

```
ice-cream-sales/
├── src/
│   ├── components/
│   │   ├── Charts/
│   │   ├── Upload/
│   │   └── Analysis/
│   ├── utils/
│   ├── styles/
│   └── App.jsx
├── public/
├── tests/
└── README.md
```
