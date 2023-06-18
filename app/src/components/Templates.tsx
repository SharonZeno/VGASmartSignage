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

const tiers = [
  {
    title: 'Template 1',
    description: [
        'some explanation about',
        'the template',
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


    const handleOnClickTemplate1 = () => {
        setShowTemplate1(true);
      };

      const handleOnClickTemplate2 = () => {
        setShowTemplate2(true);
      };
    
    const defaultTheme = createTheme();
    return (
        <ThemeProvider theme={defaultTheme}>
        {(!showTemplate1 && !showTemplate2) ?
        <div>
        <GlobalStyles styles={{ ul: { margin: 0, padding: 0, listStyle: 'none' } }} />
        <CssBaseline />
        <Container disableGutters maxWidth="sm" component="main" sx={{ pt: 8, pb: 6 }}>
            <Typography
            component="h1"
            variant="h2"
            align="center"
            color="text.primary"
            gutterBottom
            >
            VGA Smart Signage
            </Typography>
            <br></br>
            <h2> Choose Your Template</h2>
        </Container>
        <Container maxWidth="md" component="main">
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
        </Container> </div> : 
        <div></div> }

        {showTemplate1 ?
        <Template1 setShowTemplate1={setShowTemplate1}></Template1> :
        <div></div>
        }

        {showTemplate2 ?
        <Template2 setShowTemplate2={setShowTemplate2}></Template2> :
        <div></div>
        }
        </ThemeProvider>
    );
}