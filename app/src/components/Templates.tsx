import * as React from 'react';
import { createTheme, ThemeProvider } from '@mui/material/styles';
import Box from '@mui/material/Box';
import Button from '@mui/material/Button';
import Card from '@mui/material/Card';
import CardActions from '@mui/material/CardActions';
import CardContent from '@mui/material/CardContent';
import CardHeader from '@mui/material/CardHeader';
import CssBaseline from '@mui/material/CssBaseline';
import Grid from '@mui/material/Grid';
import Typography from '@mui/material/Typography';
import GlobalStyles from '@mui/material/GlobalStyles';
import Container from '@mui/material/Container';
import { Template1 } from './Template1';
import { Template2 } from './Template2';
import logo from './logo.jpg';
import { TextField } from '@mui/material';

const tiers = [
  {
    title: 'Template 1',
    description: [
        'conference schedule',
        'template',
    ],
    buttonText: 'Choose',
    buttonVariant: 'outlined',
  },
  {
    title: 'Template 2',
    description: [
        'some explanation about',
        'the template',
    ],
    buttonText: 'Choose',
    buttonVariant: 'outlined',
  },
];


export const Templates = () => {

    const [showTemplate1, setShowTemplate1] = React.useState<boolean>(false);
    const [showTemplate2, setShowTemplate2] = React.useState<boolean>(false);
    const [showChooseTemplate, setShowChooseTemplate] = React.useState<boolean>(false);
    const [controller, setController] = React.useState<string>('');

    const handleOnClickEnter = () => {
        setShowChooseTemplate(true);
      };

    const handleOnClickTemplate1 = () => {
        setShowTemplate1(true);
      };

      const handleOnClickTemplate2 = () => {
        setShowTemplate2(true);
      };

      const handleControllerIDChange = (e: React.ChangeEvent<HTMLInputElement>) => {
        e.preventDefault();
        setController(e.target.value); 
      }
    
      const handleOnGoBackClick = () => {
        setShowChooseTemplate(false);
    }

     const defaultTheme = createTheme({
        typography:{
        fontFamily: 'Roboto Slab ,sans-serif',
        },        
    });

    return (
        <div>
        {(!showTemplate1 && !showTemplate2) ?
        <div>
        <div  style={{ backgroundColor: '#60829D', paddingTop: '20px', paddingBottom: '20px'}}>
        {showChooseTemplate ? <div>
        <Box sx={{ flexGrow: 1 }} />
                  <Box sx={{ display: { xs: 'none', md: 'flex' }, gap: 1}}>
                  <Button 
                    variant="outlined" 
                    size="medium" 
                    onClick={handleOnGoBackClick} 
                    sx={{borderColor: "white", color: "white"}}>
                        Go Back
                    </Button>
                  </Box> </div>: <div></div>}
        <Box sx={{mb: -5}}>
        <img src={logo} alt="" width={70}/>
        </Box>
        <Container disableGutters maxWidth="sm" component="main" sx={{ pt: 8, pb: 6 }}>
        <ThemeProvider theme={defaultTheme}>
        <Typography variant="h1" style={{ fontStyle: "Roboto Slab", fontFamily: 'sans-serif', fontSize: '3.5rem', fontWeight: 700, marginBottom: '16px', color: 'white' }}>
            VGA Smart Signage{" "}
            </Typography>
            {/* <Box sx={{  fontStyle: 'oblique',fontWeight: 'light', mb: 0.05, color: 'white'}}> */}
            <Typography variant="h4" style={{ fontStyle: 'oblique', color: 'white', fontWeight: 400, marginBottom: '32px' }}>
             Back to the Future
            {/* </Box> */}
            </Typography>
            </ThemeProvider>
        </Container>
        </div>
        
        {/* <ThemeProvider theme={defaultTheme}> */}

    
        <GlobalStyles styles={{ ul: { margin: 0, padding: 0, listStyle: 'none' } }} />
        <CssBaseline />
        <br></br>

        {!showChooseTemplate ? 
        <Container component="main" maxWidth="xs">
        <Box component="form" noValidate sx={{ mt: 1 }}>
          <Typography variant="subtitle1" gutterBottom >
            Enter Controller ID
          </Typography>
          <TextField
              margin="normal"
              fullWidth
              name="controllerID"
              type="controllerID"
              id="controllerID"
              onChange={handleControllerIDChange}
            />
             <Button
              type="submit"
              fullWidth
              variant="outlined"
              sx={{ mt: 3, mb: 2 }}
              onClick={handleOnClickEnter}
            >
              Enter
            </Button>
            </Box>
            </Container> :
                <div>
        <Container maxWidth="md" component="main" sx={{ mt: 0.05}}>
            <Grid container spacing={5} alignItems="center">
            {tiers.map((tier) => (
                // Enterprise card is full width at sm breakpoint
                <Grid
                item
                key={tier.title}
                xs={18}
                sm={18}
                md={6}
                >
                <Card>
                    <CardHeader
                    title={tier.title}
                    titleTypographyProps={{ align: 'center' }}
                    subheaderTypographyProps={{
                        align: 'center',
                    }}
                    sx={{
                        backgroundColor: (theme) =>
                        theme.palette.mode === 'light'
                            ? theme.palette.grey[200]
                            : theme.palette.grey[700],
                    }}
                    />
                    <CardContent>
                    <Box
                        sx={{
                        display: 'flex',
                        justifyContent: 'center',
                        alignItems: 'baseline',
                        mb: 2,
                        }}
                    >
                    </Box>
                    <ul>
                        {tier.description.map((line) => (
                        <Typography
                            component="li"
                            variant="subtitle1"
                            align="center"
                            key={line}
                        >
                            {line}
                        </Typography>
                        ))}
                    </ul>
                    </CardContent>
                    <CardActions>
                    <Button
                        fullWidth
                        variant={tier.buttonVariant as 'outlined' | 'contained'}
                        onClick={tier.title === 'Template 1' ? handleOnClickTemplate1 : handleOnClickTemplate2}
                    >
                        {tier.buttonText}
                    </Button>
                    </CardActions>
                </Card>
                </Grid>
            ))}
            </Grid> 
        </Container> </div>}</div> : 
        <div></div> }

        {showTemplate1 ?
        <Template1 setShowTemplate1={setShowTemplate1} controller={controller}></Template1> :
        <div></div>
        }

        {showTemplate2 ?
        <Template2 setShowTemplate2={setShowTemplate2} controller={controller}></Template2> :
        <div></div>
        }
        {/* </div></ThemeProvider> */}    
        </div>
    );
}